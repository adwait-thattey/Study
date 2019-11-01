import shared
import constants


def gen_stop_words_dict():
    f = open(constants.STOP_WORDS_FILE, mode="r")
    lines = f.readlines()
    f.close()
    words = [l.strip('\n').strip(' ') for l in lines]

    for i in words:
        shared.STOP_WORDS.add(i)
