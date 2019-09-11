process_normal_query_help = """
    The query can be something like:
    word1 AND word2 OR word2
    Evaluation is from left to right.
    This will return all documents which either contain both word1 and word2 or simple contain word3
    Put NOT before the word to invert
    Example: word1 AND NOT word2
    """

find_matching_words = """
    Give a word having a * and i will return all matching words from documents
    Example if you give " w*t "
    I will return wet, west etc. if they exist
    The * can appear anywhere
    """

process_wild_card_query = """
    The query can be something like:
    wo* AND *d2 OR word2
    Evaluation is from left to right.
    First will find all matching words
    This will return all documents which either contain both wo* and *d2 or simple contain word2
    Put NOT before the word to invert
    Example: *d1 AND NOT wo*
    """        