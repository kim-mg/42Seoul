import sys

def w_html(ele_tab):
    html_f ="""
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <title>Periodic table of the elements</title>
            <style>
                header {
                    width: 3600px;
                    text-align: center;
                    font-size: 40px;
                }

                table {
                    border-collapse: collapse;
                }

                td {
                    width: 200px;
                    font-size: 20px;
                }

                li {
                    font-size: 17px;
                }
            </style>
        </head>
        <body>
            <header>
                <h2>PERIODIC TABLE</h2>
            </header>
            <div class=cont_main>
                <table>
        """
    html_r = """
                <table>
            </div>
            <footer>
            </footer>
        </body>
        </html>
    """
    main = """"""
    tab = """
        <td style="background-color: yellowgreen;border: 1px solid black; padding: 10px">
            <h4>{}</h4>
            <ul>
                <li>No {}</li>
                <li>{}</li>
                <li>{}</li>
                <li>{} electron</li>
            </ul>
        </td>
    """
    idx = 0
    for i in range(7):
        for j in range(18):
            if j == 0:
                main += "<tr>"
            if int(ele_tab[idx]["position"]) == j:
                main += tab.format(ele_tab[idx]["name"], ele_tab[idx]["number"], ele_tab[idx]["small"], ele_tab[idx]["molar"], ele_tab[idx]["electron"] + "<br>")
                idx += 1
            else:
                main += "<td></td>"
            if j == 17:
                main += "</tr>"

    f = open("periodic_table.html", "w")
    f.write(html_f + main + html_r)
    f.close()

def parsing():
    ele_tab = {}

    f = open("periodic_table.txt", "r")
    lst = f.readlines()
    idx = 0
    for line in lst:
        temp = list(map(lambda x:x.strip(), line.split("=")))
        ele_tab[idx] = {'name':temp[0]}
        ele_lst = temp[1].split(", ")
        for ele in ele_lst:
            ele_temp = list(map(lambda x:x.strip(), ele.split(":")))
            ele_tab[idx][ele_temp[0]] = ele_temp[1]
        idx += 1
    f.close()
    return ele_tab

def solution():
    ele_tab = parsing()
    w_html(ele_tab)

if __name__ == '__main__':
    solution()