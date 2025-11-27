leaks:
F 85, 107 crée des leaks
- F 122 133, 212, 212 ne dois pas marcher

check_map:
- pad map pourquoi?

Bugs:
-le joueur se téléporte
-Rectangle noir apparait 1/6 au lancement du jeu

Définitions:

Raycasting: est une technique de calcul d'image de synthèse 3D, elle consiste à projeter des rayons digitaux depuis  la position de la caméra vers la scène virtuelle, un par pixel de l'écran. Le premier objet rencontré par un rayon détermine la couleur et la luminosité du pixel correspondant, permettant de créer une vue 3D réaliste ou d'interagir avec l'environnement. 

Murs verticaux horizontaux:
Les "murs verticaux" et "murs horizontaux" ne sont pas des murs différents dans ta map, c’est juste une façon de dire :
v: si le rayon touche le côté gauche ou droit de la case.
h: si le rayon touche le côté haut ou bas de la case.