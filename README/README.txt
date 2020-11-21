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

*Environnement de d�veloppement :

Notre projet a enti�rement �tait con�u avec Qt Creator 4.2.1 (based on Qt 5.8.0) et Qt Designer, pour pouvoir r�aliser une interface graphique en utilisant la librairie OpenGL.

====================================================================

*Cr�ation du programme :

Nous avons fait tous les exercices d�crits sur le Moodle jusqu'au P13.
Pendant les premi�res semaines nous avons pass� 2/3 heures par semaine par personne. Apr�s la semaine de vacances � P�ques, la charge de travail a consid�rablement augment�. Entre mettre en place la repr�sentation graphique et optimiser l'�volution nous passions plut�t 7/8 heures sur le projet par semaine par personne. Pendant la derni�re semaine, pour finaliser le rendu et nettoyer le code �a c'est �lev� � 20 heures. Nous n'avions cependant jamais l'impression de ne pas pouvoir terminer � l'heure.

====================================================================

*Dossier "exercices" :

Ce dossier contient le projet sauvegard� � diff�rent moments de la conception, � savoir � la fin de chaque exercice du Moodle du 9 au 13. ATTENTION: ces projets ne sont pas configur�s et ne compilerons donc pas directement�

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

*Description des simulations propos�es :

	- Simulation 1 : Elle contient 4 grains et 1 plan. C'est la simulation qui �tait propos�e pour les diff�rents 				 test que nous avions � faire lors de la conception.
	- Simulation 2 : Elle contient 3 sources, 11 obstacles, et 1 zone remplie d'eau. Nous avons voulu repr�senter 				 une personne prenant une douche de grains de sables. Bien que  irr�aliste, cette simulation 				 est tr�s fun.
	- Simulation 3 : Elle contient 2 sources, 12 obstacles, et 1 plan d'eau. Celle-ci simule une planche de 			 Galton simplifi�e.
	- Simulation 4 : Elle contient 3 sources, 8 obstacles et 1 zone confin�e d'eau. Elle repr�sente un cube 			 ouvert a moiti� plein d'eau dans lequel sont positionn�s 3 obstacles.
	 		 Les sources sont plac�es au dessus de ces derniers.

====================================================================

*Utilisation du programme:

Une fen�tre interactive appara�tra o� l'on peut choisir quelle simulation on souhaite lancer gr�ce aux onglets en haut de la fen�tre. 

Apr�s avoir choisi une simulation, le bouton "D�marrer" lance la simulation dans la fen�tre, "Arr�ter" permet de l'arr�ter. 



Pour interagir avec la simulation, utiliser les touches suivantes (apr�s avoir cliqu� sur la fen�tre) :

spacebar : mettre en pause la simulation

1: �teindre/allumer les sources

Up/Down : pivoter la cam�ra autour de l�axe x

Left/Right : pivoter la cam�ra autour de l�axe y

W/S : avancer/reculer la cam�ra

A/D : pivoter la cam�ra autour de son axe x

R/F : pivoter la cam�ra autour de son axe y

Q/E : pivoter la cam�ra autour de son axe z

Home: remettre la cam�ra � la position initiale

#Pour les simulation 1 et 2:

O : d�marrer/arr�ter le mouvement des obstacles

P : changer la direction du mouvement de l'obstacle


Il est de aussi possible d'utiliser la souris pour changer le point de vue de la cam�ra.
