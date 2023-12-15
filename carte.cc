#include "carte.hh"
//#include "salle.hh"

carte::carte(const std::vector<std::vector<int>>& configuration,int widthsalle, int heightsalle) {
    // Initialisez la grille de salles
    width = configuration.size();
    height = configuration[0].size();
    configurerCarte(configuration,widthsalle,heightsalle);
}

void carte::ajouterSalle(int x, int y, int widthsalle, int heightsalle, sf::Color color,std::string hautbas, std::string gauchedroite){
    grille[x][y] = salle(widthsalle,heightsalle,color,hautbas,gauchedroite);
}

void carte::configurerCarte(const std::vector<std::vector<int>>& configuration,int widthsalle, int heightsalle) {
    // Assurez-vous que la taille de la configuration correspond à la taille de la carte
    
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            // Utilisez la valeur de la configuration pour déterminer les paramètres de la salle
            int valeur = configuration[x][y];
            
            ajouterSalle(x ,y ,widthsalle, heightsalle, sf::Color::Blue, 0, 0);
        }
    }
}
