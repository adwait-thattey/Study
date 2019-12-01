import json


class Index:
    def __init__(self):
        self.term_count = dict()
        self.length = 0

    def calc_length(self):
        sum = 0
        for x in self.term_count.values():
            sum += x * x

        sum = sum ** 0.5

        self.length = sum


class CodeSnippet:
    def __init__(self, lang, snippet):
        self.language = lang
        self.snippet = snippet
        self.index = None

    @property
    def export_object(self):
        obj = {
            "language": self.language,
            "snippet": self.snippet
        }

        return obj

    def to_json(self):
        json_string = json.dumps(self.export_object)
        return json_string

    @classmethod
    def from_json(cls, json_string):
        # parse json and return object of class
        # return cls(...)
        return None


class APIDoc:
    def __init__(self, url, name, doc_text, code_snippets, out_links, lang):
        self.url = url
        self.name = name
        self.text = doc_text
        self.codes = [CodeSnippet(lang, cs) for cs in code_snippets]
        self.out_links = out_links
        self.index = None

    @property
    def export_object(self):
        obj = {
            "url": self.url,
            "name": self.name,
            "text": self.text,
            "codes": [snip.export_object for snip in self.codes],
            "out_links": json.dumps(self.out_links)
        }
        return obj

    def to_json(self):
        json_string = json.dumps(self.export_object)

        return json_string

    @classmethod
    def from_json(cls, json_string):
        # parse json and return object of class
        # return cls(...)
        return None


class Answer:
    def __init__(self, url, text, code_snippets, out_links, upvotes, lang):
        self.url = url
        self.text = text
        self.codes = [CodeSnippet(lang, cs) for cs in code_snippets]
        self.out_links = out_links
        self.upvotes = upvotes
        self.index = None

    @property
    def export_object(self):
        obj = {
            "url": self.url,
            "text": self.text,
            "codes": [snip.export_object for snip in self.codes],
            "out_links": self.out_links,
            "upvotes": self.upvotes
        }

        return obj

    def to_json(self):
        json_string = json.dumps(self.export_object)
        return json_string

    @classmethod
    def from_json(cls, json_string):
        # parse json and return object of class
        # return cls(...)
        return None


class Question:
    def __init__(self, url, question_id, title, text, code_snippets, out_links, answers, lang):
        self.url = url
        self.id = question_id
        self.title = title
        self.text = text
        self.codes = [CodeSnippet(lang, cs) for cs in code_snippets]
        self.out_links = out_links
        self.answers = answers
        self.index = None

    @property
    def export_object(self):
        obj = {
            "id": self.id,
            "url": self.url,
            "title": self.title,
            "text": self.text,
            "codes": [snip.export_object for snip in self.codes],
            "out_links": self.out_links,
            "answers": [ans.export_object for ans in self.answers]
        }

        return obj

    def to_json(self):
        json_string = json.dumps(self.export_object)
        return json_string

    @classmethod
    def from_json(cls, json_string):
        # parse json and return object of class
        # return cls(...)
        return None
