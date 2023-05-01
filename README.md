# systeme_gestion_entreprise
Il s’agit de concevoir et de développer une application de gestion de projet et d’affectation de tâches d’une entreprise informatique.
L’étude de la problématique et des besoins a fait apparaître les éléments
suivants :
● Une entreprise a

■ Un ensemble d’employés
■ Un ensemble de projets

● Un projet a :

■ un nom du client (string)
■ un code projet (string)
■ un ensemble de tâches considérées comme tâches restantes.
■ une fonction pour récupérer les tâches incomplètes. Une tâche est dite incomplète
si sa quantité est supérieure à 0.
■ une fonction (prenant comme paramètre une tâche effectuée) pour mettre à jour
l’état de ses tâches restantes. Cette fonction utilise l’opérateur == pour chercher la
tâche dont la quantité sera réduite (voir exemple).

● Une tâche a :

■ un code projet (string)
■ un type qui varie entre “DEV” ou “TEST”
■ une spécialité qui peut être soit “MOBILE”, “BACKEND” ou “FRONTEND”
■ une quantité unitaire de travail (int)
■ surcharger l’opérateur de vérification d’égalité (==). Deux tâches sont égales si
elles ont le même code du projet, le même type et la même spécialité.

● Un employé :

■ a un numero de cin
■ a une spécialité (une parmi les valeurs suivantes “FRONTEND”, “BACKEND” ou
“MOBILE”.
■ a une capacité (quantité unitaire) de travail maximale (int)

1

■ a une capacité de travail restante initialisée à sa capacité maximale. à chaque
tâche affectée à cet employé, la quantité de celle-ci sera soustraite de la capacité
restante de l’employé.
■ doit être capable d’indiquer s’il est disponible ou pas (capacité de travail restante >
0)
■ a un ensemble de tâches affectées (toutes les tâches qui lui ont été affectées)
■ a un ensemble de tâches restantes (toutes les tâches qui lui ont été affectées
avec leurs quantités restantes
(i.e. tâchesRestantes[i]<=tâchesAffectees[i]).
■ doit être capable de choisir et de retourner une tâche qu’il veut faire parmi un
ensemble de tâches passées comme paramètre. il retourne une tâche à une
quantité 0 si aucune tâche ne correspond à sa spécialité et au type de tâche qu’il
peut effectuer. s’il trouve une tâche qui lui correspond alors il retourne une tâche
similaire avec la quantité maximale entre la quantité de la tâche et la capacité
restante qu’il a.
■ doit être capable de retourner le travail fini qui est l’ensemble des tâches à faire
complétées (leur tâcheRestante a une quantité égale à zéro)

Un développeur ne choisit que les tâches de type DEV et demandant une spécialité équivalente à la
sienne. Cependant, un testeur ne choisit que les tâches de type TEST et demandant une spécialité
équivalente à la sienne.
L’entreprise doit fournir les méthodes suivantes :
● getTâchesIncompletes : toutes les tâches restantes de tous ses projets et dont la quantité est
supérieure à zéro.
● distribuerTravail : collecte toutes les tâches incomplètes de tous ses projets, puis pour chacun
des employés:
○ s’il est disponible alors lui demander de choisir la tâche qu’il peut faire
○ si la tâche retournée a une quantité > 0 (il a trouvé une tâche qui lui correspond) alors la
lui affecter.

● collecterTravailFini: collecte le travail fini de tous les employés et met à jour le projet lui
correspondant en mettant à jour la quantité restante de la tâche en fonction de la tâche effectuée.
Remarques:
● La manière de choisir la tâche à faire est différente selon la nature de l’employé (développeur ou
testeur ou d’autres non modélisés dans cette version de l’application).
● La phase de travail pendant laquelle les employés travaillent et réduisent les quantités de tâches
restantes n’est pas prise en compte dans cet énoncé.
● Aucune suppression d’un élément d’un tableau/vecteur n’est requise dans tout l’énoncé.
● Aucune exécution n’est attendue de votre livrable (pas de main). Cependant, le code devra être
compilable sans erreurs.
