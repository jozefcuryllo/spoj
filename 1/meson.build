project('spoj', 'cpp')

gtest_dep = dependency('gtest_main')

program = executable('program', 'Main.cpp')
program_test = executable('program_test', 'MainTest.cpp', dependencies: [gtest_dep], install: true)

test('tests', program_test)