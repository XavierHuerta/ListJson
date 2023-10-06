// ListJson.cpp: define el punto de entrada de la aplicación.
//

#include "ListJson.h"


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <filesystem>

//using namespace std;
//namespace fs = std::filesystem;

// Funcion para listar archivos en un directorio y obtener sus tamaños
std::map<std::string, int> listFiles(const std::string& directoryPath) {
    std::map<std::string, int> fileInfo;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (std::filesystem::is_regular_file(entry)) {
            std::string filename = entry.path().filename().string();
            int size = static_cast<int>(std::filesystem::file_size(entry.path()));
            fileInfo[filename] = size;
        }
    }

    return fileInfo;
}

int main(int argc, char const* argv[]) {
    if (argc < 2) {
        std::cerr << "No se ingreso una URL de directorio válida" << std::endl;
        exit(1);
    }

    std::string directoryPath = argv[1];
    std::map<std::string, int> fileInfo = listFiles(directoryPath);

    // Creamos un JSON manualmente
    std::string json = "{ \"files\": [";

    for (const auto& pair : fileInfo) {
        json += "\t{\"name\":\"" + pair.first + "\",\"size\":" + std::to_string(pair.second) + "},\n";
    }

    if (!fileInfo.empty()) {
        json.pop_back(); // Eliminamos la última coma
    }

    json += "]\n}";

    // Mostramos la cadena JSON
    std::cout << json << std::endl;

    return 0;
}
