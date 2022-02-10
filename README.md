# Push_swap

Faire un programme composé de 2 listes nommées **a** et **b**.  
Ce programme prendra en paramètre la liste **a** sous la forme d’une liste de nombres négatifs et/ou positifs, qui ne peuvent pas être dupliqués, et en quantité aléatoire.  
La liste **b** est vide. 

Le but est de trier la pile avec le moins d’opérations possibles, avec comme opération :

> **sa** : swap a - intervertit les 2 premiers éléments au sommet de la pile a.  
> **sb** : swap b - intervertit les 2 premiers éléments au sommet de la pile b.  
> **ss** : sa et sb en même temps  
> **pa** : push a - prend le premier élément au sommet de b et le met sur a.  
> **pb** : push b - prend le premier élément au sommet de a et le met sur b.  
> **ra** : rotate a - le premier élément de a devient le dernier.  
> **rb** : rotate b - le premier élément de bdevient le dernier.  
> **rr** : ra et rb en meme temps.  
> **rra** : le dernier élément de a devient le premier.  
> **rrb** : le dernier élément de b devient le premier.  
> **rrr** : rra et rrb en même temps.  

###  Fonctions autorisées

```write```  
```read```  
```malloc```  
```free```  
```error```  
