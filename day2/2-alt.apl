#!/bin/dyalogscript
l←⊃⎕NGET'./input.txt'1
⎕←⌽+⌿↑{
  n←(⊃⍤//⍤⎕VFI)¨⍵⊆⍨⍵∊⎕D
  c←0~⍨⊃1 2 3+.×'red' 'green' 'blue'⍷¨⊂⍵
  z←0 0 0
  (×/z),(⊃n)×(z⊣{⊢z[⍺]←⌈/n[1+⍵]}⌸c)∧.≤12 13 14
}¨l