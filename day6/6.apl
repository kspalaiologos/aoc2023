#!/bin/dyalogscript
l←⊃⎕NGET'input.txt'1⋄d←⊃⍤(//⎕vfi)
f←{-/⌊.5×⍺+1 ¯1×.5*⍨(⍺*2)-4×⍵}
⎕←×/⊃f¨/d¨l⋄⎕←⊃f/(⊢d⍤∊⍤⊆⍨∊∘⎕D)¨l