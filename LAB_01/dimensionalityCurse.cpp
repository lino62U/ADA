#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>

using namespace std;

// Clase para representar un punto en n dimensiones
class Point {
public:
    vector<double> dimensions;

    Point(int dimension) {
        dimensions.resize(dimension);
    }
};

// Función para calcular la distancia euclidiana entre dos puntos
double euclideanDistance(const Point& p1, const Point& p2) {
    double sum = 0.0;
    for (size_t i = 0; i < p1.dimensions.size(); ++i) {
        double diff = p1.dimensions[i] - p2.dimensions[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

// Función para calcular las distancias entre todos los pares de puntos
vector<double> calculateDistances(const vector<Point>& points) {
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
vector<Point> generateRandomPoints(int numPoints, int dimension) {
    vector<Point> points(numPoints, Point(dimension));
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < numPoints; ++i) {
        for (int j = 0; j < dimension; ++j) {
            points[i].dimensions[j] = dis(gen);
        }
    }

    return points;
}

// Función para generar un archivo de texto con las distancias
void saveDistancesToFile(const vector<double>& distances, int dimension) {
    string filename = "distances_d" + to_string(dimension) + ".txt";
    ofstream outFile(filename);

    for (double distance : distances) {
        outFile << distance << endl;
    }
    outFile.close();
}

int main() {
    //vector<int> dimensions = {2};
    vector<int> dimensions = {10, 50, 100, 500, 1000, 2000, 5000};
    for (int d : dimensions) {
        vector<Point> points = generateRandomPoints(100, d);

        vector<double> distances = calculateDistances(points);
        cout << "d: " << distances.size() << endl;
        saveDistancesToFile(distances, d);
    }

    return 0;
}
