import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages

def generate_histogram(data_file, dimension, pdf_pages):
    with open(data_file, 'r') as file:
        distances = [float(line.strip()) for line in file]

    num_bins = 70  # Puedes ajustar el número de bins según tus necesidades
    plt.hist(distances, bins=num_bins, edgecolor='black')
    plt.xlabel('Distancia')
    plt.ylabel('Frecuencia')
    plt.title(f'Histograma de Distancias (Dimensión {dimension})')
    #plt.xlim(0, 30)  # Establecer límites en el eje x
    #plt.ylim(0, 350)  # Establecer límites en el eje y
    plt.grid(True)  # Mostrar cuadrícula en la gráfica



    # Agregar la página actual al PDF
    pdf_pages.savefig()

    plt.close()

if __name__ == '__main__':
    dimensions = [10, 50, 100, 500, 1000, 2000, 5000]

    # Crear un objeto PdfPages para guardar todas las páginas en un solo PDF
    pdf_file = 'histogram_combined.pdf'
    pdf_pages = PdfPages(pdf_file)

    for d in dimensions:
        data_file = f'distances_d{d}.txt'
        generate_histogram(data_file, d, pdf_pages)

    # Cerrar el objeto PdfPages para finalizar el archivo PDF
    pdf_pages.close()
