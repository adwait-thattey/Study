import requests
from bs4 import BeautifulSoup
import os
import models


def get_page(url, writeto=None, title=None):
    res = requests.get(url)
    if res.status_code == 200:
        if writeto:
            if title:
                f = open(os.path.join(writeto, title.replace('/', '-')), mode="w")
            else:
                url_last_part = url.split('/')[-1]
                f = open(os.path.join(writeto, url_last_part), mode="w")
            f.write(res.text)
            f.close()

    return res


def get_page_soup(url, writeto=None, title=None):
    res = get_page(url, writeto=writeto, title=title)
    soup = BeautifulSoup(res.text, 'html.parser')
    return soup


def parse_answer(answer_soup: BeautifulSoup):
    answer_content_soup = answer_soup.find('div', attrs={'class': 'post-text'})
    answer_upvote_count_soup = answer_soup.find('div', attrs={'itemprop': 'upvoteCount'})
    upvotes = 0
    if answer_upvote_count_soup:
        upvotes = int(answer_upvote_count_soup['data-value'])
    else:
        print("[DEBUG]", "Failed to find upvote count")

    outlinks_soup = answer_content_soup.findAll('a', href=True)
    outlinks = [a['href'] for a in outlinks_soup]

    answer_text_content = answer_content_soup.text
    code_snippets_soups = answer_content_soup.findAll('code')
    code_snippets_texts = [code.text for code in code_snippets_soups]

    answer_object = models.Answer(url="", text=answer_text_content, code_snippets=code_snippets_texts,
                                  out_links=outlinks, upvotes=upvotes, lang="java")

    return answer_object


def parse_question(page_soup: BeautifulSoup):
    qtitle = page_soup.find('title').text
    print(qtitle)
    question_block = page_soup.find('div', attrs={'class': 'question'})

    question_content_soup = question_block.find('div', attrs={'class': 'post-text'})
    # print(qcontent)

    question_text = question_content_soup.text
    question_code_snippets = question_content_soup.findAll('code')
    question_code_snippets_text = [code.text for code in question_code_snippets]

    answer_soups = page_soup.findAll('div', attrs={'class': 'answer'})
    answers = [parse_answer(ans) for ans in answer_soups]
    answers.sort(key=lambda a: a.upvotes, reverse=True)

    outlinks_soup = question_content_soup.findAll('a', href=True)
    outlinks = [a['href'] for a in outlinks_soup]

    question_object = models.Question(url="", title=qtitle, text=question_text,
                                      code_snippets=question_code_snippets_text,
                                      out_links=outlinks, answers=answers, lang="java")

    return question_object


def parse_from_file(file):
    f = open(file, mode="r")
    q2_raw = f.read()
    f.close()

    soup2 = BeautifulSoup(q2_raw, 'html.parser')

    question = parse_question(soup2)

    print("question parsed")
    return question


if __name__ == "__main__":
    file = "dataset/questions/raw/using-filechannel-to-write-any-inputstream?.html"
    parse_from_file(file)
