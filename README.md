# 42-pipex 🔧

| :large_blue_circle: Circle | Project | :white_check_mark: Grade | Completion Date |
| --- | --- | --- | --- |
| 2 | pipex | 100/100 | 12/11/2021 |

This project provides an opportunity for an in-depth exploration of a UNIX mechanism that participants are already acquainted with through its utilization within their program.

Through hands-on engagement, individuals will delve into the intricacies of this mechanism, gaining a deeper understanding of its functionalities and applications within the context of their programming endeavors.

Here's a thorough explanation of the program's logic, should anyone need it :

```
PIPEX:

1 arguments

- chopper la commande

./pipex in "cat -e" cmd out

int main(int ac, char **av, char **env)

env -> PATH
PATH[??]

PATH[0] + '/' + 'cmd'

access(path, F_OK) == 0 => le fichier existe
access(path, X_OK) == -1 => permission denied

execve(path, char **args, env);

- ouvrir les fichiers

access(in, F_OK) == -1 => no such file
access(in, R_OK) == -1 => permission denied

access(out, F_OK) == -1 => no such file
access(out, R_OK) == -1 => permission denied

int fdin = open(in, O_RDONLY);
int fdout = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);




- pipe

0 = in
1 = out
2 = err

int fds[2];

fds[0] = 34;
fds[1] = 35;

pipe(fds);

34 -> lire
35 -> ecrire


35 -> 34

func()
{
	
	int fds[2];
	
	fds[0] = 34;
	fds[1] = 35;
	
	pipe(fds); // pipe_up

	pid == fork();
	if (pid == 0)
	{

		35 -> 34
		// trouver la commande
		// ouvrir les fichiers => fdin
		dup2(fdin, 0);

		close(fds[0]);
		dup2(35, 1); // pipe_in

		execve(path, char **args, env);
		exit (0);
	}

	close(fds[1]); // pipe_down

	pid == fork();
	if (pid == 0)
	{
		35 -> 34
		// trouver la commande
		// ouvrir les fichiers => fdout

		dup2(34, 0); // pipe_in

		dup2(fdout, 1); 

		0 = pipe-r
		1 = fdout
		2 = err
		34 = pipe-r
		execve(path, char **args, env);
		exit (0);
	}

	close(fds[0]); //pipe_down
	int	status;
	while (wait(&status) != -1)
	{}
}

###################################################################

0 - vérifier le nombre d'argument

	in "cmd1" "cmd2" out

1 - récupérer les commandes et leurs arguments
	char	**cmd1 = split(cmd1, ' ');
	char	**cmd2 = split(cmd2, ' ');

// cmd1[0] => nom de ton éxecutable

2 - récupérer les chemins (PATH) dans env

	2.1 - trouver ce qui commence par "PATH=" dans env

	2.2 - récupérer ce qui se trouve après le '='

	2.3 - le splitter sur ':' => char **paths;

		paths[0] = /usr/bin
		paths[1] = /bin

3 - ouvrir le pipe fds[2] (fonction pipe)
	fds[0] lire
	fds[1] écrire

4	- fork de la première commande
		// parent
		if (fork() == 0) // creation de l'enfant
		{
			// enfant
		}
		// parent

	4.1 - fermer fds[0] => on ne veut pas lire dans le pipe

	4.2 - dup2(fds[1], 1) => écrire dans le pipe

	4.3 - vérifier si le fichier in existe
		access();
	4.4 - vérifier si on peut lire le fichier in
		access();
	4.5 - ouvrir le fichier in
		dup2();

	4.6 - trouver notre commande (parcourir les paths, jusqu'à trouver un fichier qui existe)
		/usr/bin + / + nom de ta commande => chemin
		access(chemin, F_OK);

	4.7 - vérifier si on peut l'éxecuter
		access();

	4.8 - execution
		execve(chemin_vers_commande, cmd1, env));

	4.9 - libération de la mémoire

	4.10 - exit(1);

5	- fermer fds[1] => on n'a plus besoin d'écrire dans le pipe

6	- fork de la deuxième commande
	if (fork() == 0)

	6.2 - dup2(fds[0], 0) => on veut lire dans le pipe

	6.3 - vérifier si le fichier out existe
			access();
		6.3.1 - si le fichier existe pas, le créer
			O_CREAT
		6.3.2 - s'il existe, vérifier si on peut écrire dedans, et le remplacer
			O_TRUNC

	6.5 - ouvrir le fichier out
		open();

	6.6 - trouver notre commande (parcourir les paths, jusqu'à trouver un fichier qui existe)
		/usr/bin + / + nom de ta commande => chemin
		access(chemin, F_OK);

	6.7 - vérifier si on peut l'éxecuter
		access();

	6.8 - execution !
		execve(chemin_vers_commande, cmd2, env));

	6.9 - libération de la mémoire

	6.10 - exit(1);

7	- fermer fds[0]

8	- attendre les gamins (processus enfant)
	wait();

9	- libérer la mémoire

```
