class CodeSnippet:
    def __init__(self, lang, snippet):
        self.language = lang
        self.snippet = snippet


class APIDoc:
    def __init__(self, url, doc_text, code_snippets, lang):
        self.url = url
        self.text = doc_text
        self.codes = [CodeSnippet(lang, cs) for cs in code_snippets]


class Answer:
    def __init__(self, url, text, code_snippets, out_links, upvotes, lang):
        self.url = url
        self.text = text
        self.codes = [CodeSnippet(lang, cs) for cs in code_snippets]
        self.out_links = out_links
        self.upvotes = upvotes


class Question:
    def __init__(self, url, title, text, code_snippets, out_links, answers, lang):
        self.url = url
        self.title = title
        self.text = text
        self.codes = [CodeSnippet(lang, cs) for cs in code_snippets]
        self.out_links = out_links
        self.answers = answers
