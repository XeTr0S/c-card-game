# Card Clash

Jeu de cartes à combat automatique écrit en C, réalisé pour le Projet C de l'ESGI.

## Équipe

| Nom     | Prénom  |
|---------|---------|
| YE      | Yohan   |
| YA      | Hassrol |
| BERAICH | Ahmed   |

## Présentation

Card Clash est un jeu de cartes inspirées d'animes, avec une interface graphique. Le joueur collectionne des cartes, construit son deck puis le fait combattre :

- en **PvE** : tour infinie, histoire, raid et donjon ;
- en **PvP** : duel amical.

Le jeu se décide surtout **avant** le combat, dans la collection, la composition du deck et les synergies avec les supports. Pendant le combat, le joueur n'a aucune action à faire.

## Couverture des attendus du sujet

| Attendu                  | Réponse dans le projet |
|--------------------------|------------------------|
| Fichier de configuration | `config.ini` : résolution, volume, taux de drop, multiplicateurs de bordure, délai de recharge des packs, vitesse des combats |
| Traitement de fichiers   | Lecture de la base de cartes, chargement et sauvegarde du profil, journal des combats |
| Stockage de données      | Profil joueur : cartes possédées, monnaie, niveau, decks, upgrades |
| Interface graphique      | raylib |
| À vérifier               | Images des cartes et sons (raylib), API web (Jikan / AniList) pour récupérer la popularité des animes |

## Modes de jeu

### PvE

- L'adversaire a un deck de 4 cartes. Leurs stats sont fixées selon le palier, mais les cartes elles-mêmes sont tirées au hasard dans l'index des cartes disponibles.
- Modes :
  - **Tour infinie** : la difficulté augmente à chaque étage ;
  - **Histoire** : niveaux fixes ;
  - **Raid** et **Donjon** : boss et séries de combats.

### PvP

- Un joueur en invite un autre. Les deux arrivent sur l'écran de combat et celui qui a lancé le duel joue en premier.
- Le combat se déroule seul, sans aucune action pendant les tours.

## Règles de combat

- Chaque joueur a **4 cartes terrain**, dont l'ordre fixe l'ordre de passage, et **4 cartes support**, chacune rattachée à une carte terrain.
- Une seule carte combat à la fois, en un contre un, et les tours alternent.
- Une carte morte est remplacée par la suivante de la liste.
- Un joueur perd quand plus aucune de ses cartes terrain ne peut combattre.
- Les capacités se déclenchent automatiquement à certains moments :
  - au début du combat ;
  - à l'attaque ;
  - quand la carte est touchée ;
  - à la mort de la carte.
- Capacités des cartes : boost de dégâts, soin, bouclier, gel (*freeze*), étourdissement (*stun*).
- Un support agit soit sur la carte à laquelle il est rattaché, soit sur tout le deck. Exemples de supports globaux :
  - « +10 % de dégâts à toutes les cartes » ;
  - « bouclier à la carte suivante après la mort de l'active ».

## Cartes

Une carte a une **ATK**, des **PV**, une **rareté**, une **capacité** et une **bordure**, ainsi qu'un **nom**, un **anime source** et une **image**.

- **Raretés** : Commune, Rare, Épique, Légendaire, Mythique, Heaven. Heaven est une Mythique améliorée, avec de meilleures stats.
- **Stats** : elles dépendent de la popularité de l'anime et du personnage. Au départ, ces valeurs sont écrites dans `cards.csv`. En option, elles pourront être récupérées via l'API AniList.
- **Bordures** : sans bordure, silver, gold, platine, rainbow, darkness. Chaque bordure multiplie les stats de la carte. Les valeurs se règlent dans `config.ini`, par exemple ×1 / ×2 / ×3 / ×5 / ×10 / ×20.
- La rareté et la bordure sont **indépendantes** : une Mythique peut n'avoir aucune bordure et une Commune peut être rainbow. Tout dépend du facteur *luck* du joueur.

## Progression et économie

- **Packs de cartes** : le tirage est pondéré par la rareté et par la bordure.
- **Monnaie virtuelle** : gagnée en combat, dépensée en packs.
- **Niveau joueur** : il monte en ouvrant des packs, et peut-être aussi en combattant (*à déterminer*). Il donne un revenu passif de packs.
- **Recharge passive** : par exemple 2 packs par heure, avec un plafond de stockage. Elle est calculée au lancement du jeu à partir de l'heure de dernière connexion, donc les packs s'accumulent même quand le jeu est fermé.
  > *À déterminer* : il faut gérer le cas où le joueur avance l'heure de son PC pour obtenir plus de packs.
- **Upgrades achetables** (liste non exhaustive) :
  - plus de chance ;
  - plus de butin ;
  - plus de cartes par pack ;
  - recharge plus rapide ;
  - meilleure chance d'obtenir une bordure de haut niveau.
- **Collection et decks** : le joueur choisit 4 cartes terrain et 4 supports, et peut sauvegarder plusieurs decks.

## Interface

- **Écrans** : menu principal, combat, collection, boutique de packs. Viendront plus tard la sélection du mode et l'écran de duel.
- **Combat** : entièrement automatique, avec des animations d'attaque, de dégâts et de capacités. Des indicateurs d'état (gel, bouclier, boost) montrent ce qui se passe.
- **Vitesse de combat** : ×1, ×2 ou passer, réglable dans la configuration.
