/**
    encoder func
 */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state|default_layer_state) > 0) {
        if (index == 0) { /* First encoder */
           if (clockwise) {
             tap_code16(KC_RIGHT);
           } else {
             tap_code16(KC_LEFT);
           }
        }
    } else if(get_highest_layer(layer_state|default_layer_state) == 15){
      if (index == 0) { /* First encoder */
         if (clockwise) {
           tap_code16(KC_UP);
           tap_code16(KC_UP);
           tap_code16(KC_UP);
           tap_code16(KC_UP);
         } else {
           tap_code16(KC_DOWN);
           tap_code16(KC_DOWN);
           tap_code16(KC_DOWN);
           tap_code16(KC_DOWN);
         }
      }
    }else {
      if (index == 0) { /* First encoder */
             if (clockwise) {
               tap_code16(KC_UP);
             } else {
               tap_code16(KC_DOWN);
             }
          }
    }
  return false;
}
