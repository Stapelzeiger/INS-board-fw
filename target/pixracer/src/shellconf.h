#ifndef SHELLCONF_H
#define SHELLCONF_H

/* Shell related config */
#define SHELL_MAX_LINE_LENGTH           64
#define SHELL_MAX_ARGUMENTS             5
#define SHELL_MAX_HIST_BUFF             8 * SHELL_MAX_LINE_LENGTH
#define SHELL_USE_HISTORY               TRUE
#define SHELL_USE_COMPLETION            TRUE
#define SHELL_MAX_COMPLETIONS           8
#define SHELL_USE_ESC_SEQ               TRUE
#define SHELL_PROMPT_STR                "ch> "
#define SHELL_NEWLINE_STR               "\r\n"

#define SHELL_CMD_THREADS_ENABLED       FALSE
#define SHELL_CMD_TEST_ENABLED          FALSE

#endif /* SHELLCONF_H */
