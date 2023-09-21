
#include "iostream"
#include "vector"
#include "random"
#include "cmath"
#include "fstream"
using namespace std;

// Función para calcular la distancia euclidiana entre dos puntos
double euclideanDistance(const vector<double>& p1, const vector<double>& p2) {
    double sum = 0.0;
    for (size_t i = 0; i < p1.size(); ++i) {
        double diff = p1[i] - p2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}


// Función para calcular las distancias entre todos los pares de puntos
vector<double> calculateDistances(const vector<vector<double>>& points) {
    vector<double> distances;

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double distance = euclideanDistance(points[i], points[j]);
            distances.push_back(distance);
        }
    }

    return distances;
}

// Función para generar puntos aleatorios en una dimensión d
vector<vector<double>> generateRandomPoints(int numPoints, int dimension)
{
    vector<vector<double>> points(numPoints, vector<double>(dimension));
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < numPoints; ++i) {
        for (int j = 0; j < dimension; ++j) {
            points[i][j] = dis(gen);
        }
    }

    return points;
}


// Función para generar un archivo de texto con las distancias
void saveDistancesToFile(const std::vector<double>& distances, int dimension) {
    std::string filename = "distances_d" + std::to_string(dimension) + ".txt";
    std::ofstream outFile(filename);

    for (double distance : distances) {
        outFile << distance << std::endl;
    }

    outFile.close();
}

int main()
{
    vector<int> dimensions = {10, 50, 100, 500, 1000, 2000, 5000};
    //vector<int> dimensions = {10};
    for (int d : dimensions) {
        vector<vector<double>> points = generateRandomPoints(100, d);

        vector<double> distances = calculateDistances(points);
        cout<<"d: "<<distances.size()<<endl;
        //generateHistogram(distances, 50, d);
        saveDistancesToFile(distances, d);
    }

    return 0;
}
