import random
from decimal import *
from time import time

import matplotlib.pyplot as plt
import pandas as pd

#
# METER ESTE ARCHIVO EN LA MISMA CARPETA DONDE ESTAN LOS .CSV, y luego ejecutar: python experimento_1.csv
# INSTALAR LO SIGUIENTE CON LA TERMINAL:
# brew install pkg-config
# pip install matplotlib
# pip install pandas

def graficoGeneral():
    df = pd.read_csv('experimento_8.csv', sep=',', names = ["n", "fuerza bruta", "backtracking","meet in the middle", "programacion dinamica"])
    df.set_index("n", inplace= True)
    df.plot(logy = True)

    plt.ylabel('Tiempo')
    plt.xlabel('número de experimento')

    plt.show()

graficoGeneral()


