
static int c_frame = 0;
bool first_render = true;

static void render_anim(void) {
    if (first_render) {
        oled_write_raw_P( frame, ANIM_SIZE);
        first_render = 0;
    } else {
        change_frame_bytewise(c_frame);
    }
    c_frame = c_frame+1 > IDLE_FRAMES ? 0 : c_frame+1;
}
