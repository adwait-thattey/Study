documents_directory_name = "docs"
useless_character_list = ['\n', '.', ',', "'", '"', ';', '/', '?', '(', ')', '$', '*', '@', ' ']
special_characters = ['*', '$']
VECTOR_SIZE = 64
WEIGHTS = {
    # weights at distance 1 is 0.5 and so on...
    1: 0.5,
    2: 0.25
}
SIMILAR_TERMS_LIMIT = 10
WORD_LEN_LIMIT = 15