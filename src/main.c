#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <ftw.h>
#include <string.h>
#include <unistd.h>

int ls_callback(
	const char* path,
	const struct stat * stat,
	int tflag,
	struct FTW* ftw
) {
	if (S_ISDIR(stat->st_mode)) {
		printf(" %s\n", path);	
	}

	return 0;
}

int ls(int argc, char* argv[]) {
	if (argc >= 2) {
		chdir(argv[argc - 1]);
	}

	return nftw(".", ls_callback, 20, 0);
}

int main(int argc, char* argv[]) {
	const char* program = argv[0];

	if (strcmp(program, "ls")) {
		ls(argc, argv);
	} else if (strcmp(program, "prett")) {
		if (strcmp(argv[1], "ls")) {
			ls(argc, argv);
		}
	}
	
	return 0;
}
