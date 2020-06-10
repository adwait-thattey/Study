from bs4 import BeautifulSoup

def parse_link(link_str):
    param_pos = link_str.find('?')
    stripped_link = link_str[:param_pos] 
    if stripped_link[-4:] == ".php":
        return link_str
    return stripped_link


def parse_date(date_str):
    month_list = ['jan', 'feb', 'mar', 'apr', 'may', 'jun', 'jul', 'aug', 'sep', 'oct', 'nov', 'dec']
    day,date,month,year = date_str.split(' ')
    month_num = str(month_list.index(month.lower()[:3]) + 1)
    print(date, month_num)
    return f"{date}/{month_num}"


f = open('bday_formatted.html')
bday_raw = f.read()
f.close()

bday_csv = open("bday_list.csv", mode="w")


soup = BeautifulSoup(bday_raw, 'html.parser')
upcoming_divs = soup.findAll('div', attrs={'class':'_4-u3'})
for ud in upcoming_divs:
    
    date_blocks = ud.findAll('div', attrs={'class': '_tzi'})
    print(len(date_blocks))
    if date_blocks:
        print("date_blocks start")
        ul_blocks = ud.findAll('ul', attrs={'class':'_tzl'})
        print(len(ul_blocks))
        date_list = [parse_date( db.text.strip('\n').strip(' ').strip('\n') ) for db in date_blocks]
        print(date_list)
        full_bday_list = dict()
        if len(date_list) == len(ul_blocks):
            for i,ub in enumerate(ul_blocks):
                li_elems = ub.findAll('li', attrs={'class':'_tzm'})
                bl = list()
                for lie in li_elems:
                    a = lie.find('a')
                    name = a['title']
                    link = parse_link(a['href'])
                    bl.append((name, link))
                full_bday_list[date_list[i]] = bl
        else:
            print("Date list len does not match with ul blocks len")
        print("date_blocks end")

        print(full_bday_list)
        for date_str in full_bday_list:
            for bdays in full_bday_list[date_str]:
                csv_line = ",".join( [date_str, bdays[0], bdays[1]] )
                bday_csv.write(csv_line + "\n")


bday_csv.close()
    # if date_block:
    #     date_text = date_block.text.strip('\n').strip(' ').strip('\n')
    #     print(date_text)
    #     db_ul = ud.findAll('ul', attrs={'class':'_tzl'})
    #     print(len(db_ul))
    #     if db_ul:
    #         li_elems = db_ul.findAll('li', attrs={'class':'_tzm'})
    #         print(len(li_elems))
    #     else:
    #         print("UL not found")