#include QMK_KEYBOARD_H

typedef enum {
    SINGLE_TAP, SINGLE_HOLD, DOUBLE, TRIPLE, QUAD
} tap_dance_state_enum;

enum {
  TD_KEY = 0
};

static tap_dance_state_enum tap_dance_state;
static bool tap_dance_active = false;
static uint16_t timer;

void dance_cycle(bool override_timer) {
  if (tap_dance_active)
  {
    if (timer_elapsed(timer) > 100 || override_timer)
    {
      switch (tap_dance_state)
      {
        case SINGLE_HOLD:
        {
          SEND_STRING("QMK is the best thing ever!");
          break;
        }

        case DOUBLE:
        {
          rgblight_step_noeeprom();
          break;
        }

        case TRIPLE:
        {
          rgblight_toggle_noeeprom();
          break;
        }

        default:
          // Not needed
          break;
      }

      timer = timer_read();
    }
  }
}

void dance_finished(qk_tap_dance_state_t *state, void* user_data) {
  // Determine the current state
  switch (state->count)
  {
    case 1:
    {
      if (state->interrupted || state->pressed == 0) tap_dance_state = SINGLE_TAP;
      else tap_dance_state = SINGLE_HOLD;
      break;
    }
    case 2:
    {
      tap_dance_state = DOUBLE;
      break;
    }
    case 3:
    {
      tap_dance_state = TRIPLE;
      break;
    }
    default:
    {
      tap_dance_state = QUAD;
      break;
    }
  }

  switch (tap_dance_state)
  {
    case SINGLE_TAP:
    {
      // VS Build: CTRL+SHIFT+B
      send_string_with_delay_P(PSTR("What the fuck did you just fucking say about me, you little bitch? I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills. I am trained in gorilla warfare and I'm the top sniper in the entire US armed forces. You are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with saying that shit to me over the Internet? Think again, fucker. As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot. The storm that wipes out the pathetic little thing you call your life. You're fucking dead, kid. I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that's just with my bare hands. Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit. If only you could have known what unholy retribution your little \"clever\" comment was about to bring down upon you, maybe you would have held your fucking tongue. But you couldn't, you didn't, and now you're paying the price, you goddamn idiot. I will shit fury all over you and you will drown in it. You're fucking dead, kiddo."), 10);
      tap_dance_active = false;
      break;
    }
    case SINGLE_HOLD:
    {
      SEND_STRING("https://youtu.be/dQw4w9WgXcQ\r\n");
      tap_dance_active = false;
      break;
    }
    case DOUBLE:
    case TRIPLE:
    {
      // These are handled by the matrix_scan, which will register the appropriate rgb
      // functions every scan
      tap_dance_active = true;
      timer = timer_read();
      dance_cycle(true);
      break;
    }

    case QUAD:
    {
      // Reprogram
      reset_keyboard();
      break;
    }
  }
}

void dance_reset(qk_tap_dance_state_t *state, void* user_data)
{
  tap_dance_active = false;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_KEY] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_finished, dance_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(TD(TD_KEY))
};

void matrix_scan_user(void) {
  dance_cycle(false);
}
