original_documents_directory_path = "docs/original"
parsed_documents_directory_path = "docs/parsed"
replaceable_special_characters = {',', "'", '"', ';', '?', ':', '-'}
special_characters = ['*', '$']
VECTOR_SIZE = 512
VECTOR_REPLACE_RATIO = 0.1
WEIGHTS = {
    # weights at distance 1 is 0.5 and so on...
    1: 0.5,
    2: 0.25
}
SIMILAR_TERMS_LIMIT = 10
WORD_LEN_LIMIT = 15
DOCUMENT_LENGTH_LIMIT = 4000
null_word = "**"
