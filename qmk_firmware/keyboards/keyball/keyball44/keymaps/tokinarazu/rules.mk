RGBLIGHT_ENABLE = no

OLED_ENABLE = yes

VIA_ENABLE = yes

# COMBO_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes
REPEAT_KEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
EXTRAKEY_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
# DEFERRED_EXEC_ENABLE = yes
DEBOUNCE_TYPE = sym_eager_pk

SRC += lib/keyball/keyball.c
SRC += features/translate_ansi_to_jis.c
SRC += features/select_word.c
