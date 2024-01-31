# Projet-the-binding-of
##installation :
ATTENTION : bien vérifier avoir installé sfml 
sinon,faire sudo apt install smfl

une fois que c'est fait, plus qu'a faire make game dans le bon répertoire. Tout se compilera et l'application se lancera seul

## Le principe du jeu :
Le projet se présente comme un jeux vidéo qui (dans l’idée) se voulait reprandre l’idée du jeu original the
binding of isaac.
On incarne un étudiant anonyme qui s’est perdu dans chatelet les halles et qui cherche à regagner son
appartement à temps avant que celui-ci soit réquisitionné par des touristes venus s’y installer pour les J.O
pour ça il doit retrouver ses effets personnels en esquivant les dangers de chatelet les halles et atteindre
son métro qui arrives dans 5 minutes, dans le cas contraire c’est perdu.
Le jeu comporte 5 cartes toutes de 9 salles pour la simplicité. Le jeu se présente donc comme un genre de
jeu d’esquive finalement

Les touches pour se déplacer sont décrites au lancement.

## Commentaires succints relatifs aux contraintes.
Le jeu exploite les contraintes, nous possédons plus de 8 classes avec au moins 2 fonctions virtuelles dans Entite et Objet et 3 niveaux de hiérarchie (pour les héros et ennemis notamment). Le jeu utilise principalement les conteneurs vecteurs, nous avons aussi des matrices et un objet map pour les textures ;
Mis a part la boucle principale du jeu et peut être les ofnctions d'initialisation des cartes qui sont peu élégantes faute de temps ; aucune fonciton ne fait plus de 30 lignes.

Les choses manquantes sont : les surcharges d'opérateurs, les testcases et la gestion adéquate de la mémoire qui se contrôle avec Valgrind
