from bs4 import BeautifulSoup


def content_filter(soup):
    ignore_tags = ['head', 'title', 'meta', '?xml']
    ignore_patterns = ['......', ]
    for t in ignore_tags:
        [s.extract() for s in soup(t)]

    rel_paras = soup.findAll('p', attrs={'class': "tx1"})
    rel_lines = [p.text for p in rel_paras]

    # ignore all lines containing less than 5 words
    rel_lines = [l for l in rel_lines if len(l.split()) > 5]

    # ignore all lines containing ignore patterns

    rel_lines = [l for l in rel_lines if len([i for i in ignore_patterns if i in l]) == 0]

    rel_lines = [l.replace('\n', ' ') for l in rel_lines]
    return rel_lines


if __name__ == "__main__":
    for ix in range(2, 67):
        f = open(f"./books/brisingur/brisingur_split_{ix}.htm", mode="r")
        contents = f.read()
        f.close()

        soup = BeautifulSoup(contents, 'html5lib')

        relevant_paras = content_filter(soup)

        # pretty_paras = [p.text for p in relevant_paras]

        f = open(f"brisingur_part_{ix}.txt", mode="w")
        f.write("\n".join(relevant_paras))
        f.close()
        print(f"parsed {ix}")
