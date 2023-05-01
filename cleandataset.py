import csv
import json
import traceback
import re
regex = r'[A-Za-z]"[A-Za-z]'
regex2 = r'"[A-Za-z]"'
try:
    with open('./dataset.csv', newline='') as arquivo_csv:
        leitor_csv = csv.DictReader(arquivo_csv)
        data = {}
        for linha in leitor_csv:
       
            x = linha['production_companies'].replace("'", '"')
         
            match = re.search(regex,  x)
            match2 = re.search(regex2,  x)
            print(match)
            if x!="[]" :
                if(match==None):
                    
                    if (match2==None): 
                        print(x)
                        j = json.loads(x)
                        if linha["title"] != "" and j[0]["name"] !="":
                            data[linha["title"]] = j[0]["name"]

    with open('output.csv', 'w', newline='') as output_file:
        cabecalho = ['production_company','title'
    ]
        escritor = csv.DictWriter(output_file, fieldnames=cabecalho)

        escritor.writeheader()
        for filme, estudio in data.items():
            escritor.writerow({'title': filme, 'production_company': estudio})
except Exception:
    traceback.print_exc()
