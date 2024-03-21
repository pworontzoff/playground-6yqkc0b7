# La Courbe du dragon - programmation 5 - Le programme presque complet

## Rappel

Nous avons obtenu un bébé dragon (niveau 4) incomplet, comme ceci :

![DragonNiv4_10Virages](img/DragonNiv4_10Virages.PNG) 

Alors que la véritable courbe du dragon avec 4 plis est comme ceci :

![DragonNiv4](img/DragonNiv4.PNG) 

Avec 15 virages (et 16 segments) et non pas 10 !

Nous pourrions obtenir le dragon (niveau 4) complet en écrivant :

```C
repeat (15) {
```

au lieu de 

```C
repeat (10) {
```

Et ça marcherait ! :-)

...Mais ça ne marcherait que pour les courbes de niveau 4 ! :-(

<br><br>

Nous pouvons heureusement calculer le nombre exact de virages nécéssaires en fonction du niveau de la courbe.

Nous avons en effet noté sur norte feuille :

- niveau 1 / nombre de virages : 1
- niveau 2 / nombre de virages : 3
- niveau 3 / nombre de virages : 7
- niveau 4 / nombre de virages : 15

Et nous pouvons en fait en déduire :

- niveau n / nombre de virages : 2<sup>n</sup>-1

Cela est dû au fait qu'à chaque étape de construction de la courbe on plie la bandelette déjà pliée en 2 et donc on double le nombre d'apaisseurs :

- au départ (niveau 0), il y a 0 pli et 1 épaisseur à plier pour la prochaine étape
- Après avoir plié 1 fois (pour le niveau 1), il y a 1 pli et 2 épaisseurs à plier pour la prochaine étape
- Après avoir plié 2 fois (pour le niveau 2), il y a 1 + 2 = 3 plis et 4 épaisseurs à plier pour la prochaine étape
- Après avoir plié 3 fois (pour le niveau 3), il y a 3 + 4 = 7 plis et 8 épaisseurs à plier pour la prochaine étape
- Après avoir plié 4 fois (pour le niveau 4), il y a 7 + 8 = 15 plis et 16 épaisseurs à plier pour la prochaine étape
...

Ce qui nous donne, en résumé : 

- au départ (niveau 0), il y a 0 pli et 1 épaisseur
- Au niveau 1, il y a 1    pli  et 2  épaisseurs
- Au niveau 2, il y a 3    plis et 4  épaisseurs
- Au niveau 3, il y a 7    plis et 8  épaisseurs
- Au niveau 4, il y a 15   plis et 16 épaisseurs
...
- Au niveau n, il y a 2<sup>n</sup>-1 plis et 2<sup>n</sup> épaisseurs

En langage C, on peut calculer 2<sup>n</sup>-1 en écrivant le code suivant :

```C
pow(2,n)-1
```

Nous avons cependant un programme qui utilise le nom `etape` plutôt que n. Le code correct pour calculer le nombre de virage est donc :

```C
pow(2,etape)-1
```

et donc nous pouvons écrire :

```C
repeat (pow(2,etape)-1) {

```

au lieu de : 

```C
repeat (10) {
```

afin d'obtenir un dragon complet quel que soit son niveau !

<br><br>

## Le programme à terminer avec la toute dernière ligne !

@[drawing_dragon_9]({"stubs": ["main.c"],"command": "sh /project/target/run.sh", "project" : "drawing_dragon_9"})

**! Vous pouvez appuyer sur "Run" pour exécuter ce code et visualiser le dessin obtenu.**

*NB : si vous obtenez l'erreur "Unable to open static viewer" ou si rien ne s'affiche, ce n'est pas grave, il faut juste insister sur le bouton "run" (ou "success") et ça devrait finir par fonctionner.*
