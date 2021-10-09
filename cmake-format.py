
# -----------------------------
# Options affecting formatting.
# -----------------------------
with section("format"):

  # Disable formatting entirely, making cmake-format a no-op
  disable = False

  # How wide to allow formatted cmake files
  line_width = 80

  # How many spaces to tab for indent
  tab_size = 4

  # If true, separate flow control names from their parentheses with a space
  separate_ctrl_name_with_space = False

  # If true, separate function names from parentheses with a space
  separate_fn_name_with_space = False

  # If a statement is wrapped to more than one line, than dangle the closing
  # parenthesis on its own line.
  dangle_parens = True

   # If an argument group contains more than this many sub-groups (parg or kwarg
  # groups) then force it to a vertical layout.
  max_subgroups_hwrap = 1

  # If a positional argument group contains more than this many arguments, then
  # force it to a vertical layout.
  max_pargs_hwrap = 2

  # If a cmdline positional group consumes more than this many lines without
  # nesting, then invalidate the layout (and nest)
  max_rows_cmdline = 1

  # If the trailing parenthesis must be 'dangled' on its on line, then align it
  # to this reference: `prefix`: the start of the statement,  `prefix-indent`:
  # the start of the statement, plus one indentation  level, `child`: align to
  # the column of the arguments
  dangle_align = 'prefix'

  # If the statement spelling length (including space and parenthesis) is
  # smaller than this amount, then force reject nested layouts.
  min_prefix_chars = 4

  # If the statement spelling length (including space and parenthesis) is larger
  # than the tab width by more than this amount, then force reject un-nested
  # layouts.
  max_prefix_chars = 10

  # If a candidate layout is wrapped horizontally but it exceeds this many
  # lines, then reject the layout.
  max_lines_hwrap = 2

   # Format command names consistently as 'lower' or 'upper' case
  command_case = 'lower'

  # Format keywords consistently as 'lower' or 'upper' case
  keyword_case = 'upper'

  # A list of command names which should always be wrapped
  always_wrap = []

  # If true, the argument lists which are known to be sortable will be sorted
  # lexicographicall
  enable_sort = True

  # If true, the parsers may infer whether or not an argument list is sortable
  # (without annotation).
  autosort = False


# ------------------------------------------------
# Options affecting comment reflow and formatting.
# ------------------------------------------------
with section("markup"):
  # If comment markup is enabled, don't reflow the first comment block in each
  # listfile. Use this to preserve formatting of your copyright/license
  # statements.
  first_comment_is_literal = True


