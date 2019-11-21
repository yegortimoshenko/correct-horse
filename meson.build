project('correct-horse', 'c')

gtk = dependency('gtk+-3.0', required: false)
lib = shared_library('correct-horse', ['src/random.c'], install: true)

executable('correct-horse', 'src/main.c', install: true, link_with: [lib])

if gtk.found()
  executable('correct-horse-gtk', 'src/main-gtk.c', dependencies: [gtk], install: true, link_with: [lib])
endif
