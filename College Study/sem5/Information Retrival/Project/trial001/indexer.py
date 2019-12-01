import models
import shared
import utils
import parser
import preprocessor
import pickler
import log

import constants


@utils.enforce_types(models.Question)
def index_question(question: models.Question):
    if question.id in shared.INDEXED_QUESTIONS:
        log.debug("indexer", f"Question {question.id} already indexed")
        return

    content = preprocessor.preprocess_question_content(question.text)
    shared.INDEXED_QUESTIONS[question.id] = {"text": {}, "code": {}, "tags": {}}
    tf_dict = dict()
    for word in content.split(' '):
        if word not in tf_dict:
            tf_dict[word] = 0

        tf_dict[word] += 1

    shared.INDEXED_QUESTIONS[question.id]["text"] = tf_dict
    # print(content)


if __name__ == "__main__":
    from starter import init, end

    init()
    f1 = "dataset/questions/raw/using-filechannel-to-write-any-inputstream?.html"
    q1 = parser.parse_question_from_file(f1)
    index_question(q1)

    f2 = "dataset/questions/raw/comparing-two-array-lists.html"
    q2 = parser.parse_question_from_file(f2)
    index_question(q2)
    # print(shared.INDEXED_QUESTIONS)
    pickler.write_questions_index()
    end()
