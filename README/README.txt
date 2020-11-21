######  #     #    ######                       
#     # #     #    #     # #####   ####   ####  
#     # #     #    #     # #    # #    # #    # 
######  #######    ######  #    # #    # #      
#       #     #    #       #####  #    # #  ### 
#       #     #    #       #   #  #    # #    # 
#       #     #    #       #    #  ####   ####  

Alexandre de Skowronski & Daniel Montagna
Mai 2017

====================================================================

*Environnement de développement :

Notre projet a entièrement était conçu avec Qt Creator 4.2.1 (based on Qt 5.8.0) et Qt Designer, pour pouvoir réaliser une interface graphique en utilisant la librairie OpenGL.

====================================================================

*Création du programme :

Nous avons fait tous les exercices décrits sur le Moodle jusqu'au P13.
Pendant les premières semaines nous avons passé 2/3 heures par semaine par personne. Après la semaine de vacances à Pâques, la charge de travail a considérablement augmenté. Entre mettre en place la représentation graphique et optimiser l'évolution nous passions plutôt 7/8 heures sur le projet par semaine par personne. Pendant la dernière semaine, pour finaliser le rendu et nettoyer le code ça c'est élevé à 20 heures. Nous n'avions cependant jamais l'impression de ne pas pouvoir terminer à l'heure.

====================================================================

*Dossier "exercices" :

Ce dossier contient le projet sauvegardé à différent moments de la conception, à savoir à la fin de chaque exercice du Moodle du 9 au 13. ATTENTION: ces projets ne sont pas configurés et ne compilerons donc pas directement·

====================================================================

*Construire/lancer programme:

La commande pour construire le programme est : 
	$ qmake
	$ make

Lancer version graphique:
	$ cd Qt_GL
	$ ./projet_gl
Lance version texte:
	$ cd text
	$ ./ projet_text
====================================================================

*Description des simulations proposées :

	- Simulation 1 : Elle contient 4 grains et 1 plan. C'est la simulation qui était proposée pour les différents 				 test que nous avions à faire lors de la conception.
	- Simulation 2 : Elle contient 3 sources, 11 obstacles, et 1 zone remplie d'eau. Nous avons voulu représenter 				 une personne prenant une douche de grains de sables. Bien que  irréaliste, cette simulation 				 est très fun.
	- Simulation 3 : Elle contient 2 sources, 12 obstacles, et 1 plan d'eau. Celle-ci simule une planche de 			 Galton simplifiée.
	- Simulation 4 : Elle contient 3 sources, 8 obstacles et 1 zone confinée d'eau. Elle représente un cube 			 ouvert a moitié plein d'eau dans lequel sont positionnés 3 obstacles.
	 		 Les sources sont placées au dessus de ces derniers.

====================================================================

*Utilisation du programme:

Une fenêtre interactive apparaîtra où l'on peut choisir quelle simulation on souhaite lancer grâce aux onglets en haut de la fenêtre. 

Après avoir choisi une simulation, le bouton "Démarrer" lance la simulation dans la fenêtre, "Arrêter" permet de l'arrêter. 



Pour interagir avec la simulation, utiliser les touches suivantes (après avoir cliqué sur la fenêtre) :

spacebar : mettre en pause la simulation

1: éteindre/allumer les sources

Up/Down : pivoter la caméra autour de lÕaxe x

Left/Right : pivoter la caméra autour de lÕaxe y

W/S : avancer/reculer la caméra

A/D : pivoter la caméra autour de son axe x

R/F : pivoter la caméra autour de son axe y

Q/E : pivoter la caméra autour de son axe z

Home: remettre la caméra à la position initiale

#Pour les simulation 1 et 2:

O : démarrer/arrêter le mouvement des obstacles

P : changer la direction du mouvement de l'obstacle


Il est de aussi possible d'utiliser la souris pour changer le point de vue de la caméra.
