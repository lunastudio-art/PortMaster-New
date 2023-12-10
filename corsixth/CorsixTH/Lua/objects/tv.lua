--[[ Copyright (c) 2009 Peter "Corsix" Cawley

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. --]]

local object = {}
object.id = "tv"
object.thob = 21
object.name = _S.object.tv
object.tooltip = _S.tooltip.objects.tv
object.ticks = false
object.build_preview_animation = 5052
object.idle_animations = {
  north = 396,
  east = 398,
}
object.orientations = {
  north = {
    footprint = { {0, 0, complete_cell = true}, {0, -1, only_passable = true} }
  },
  east = {
    footprint = { {0, 0, complete_cell = true}, {1, 0, only_passable = true} }
  },
  south = {
    footprint = { {0, 0, complete_cell = true}, {0, 1, only_passable = true} }
  },
  west = {
    footprint = { {0, 0, complete_cell = true}, {-1, 0, only_passable = true} }
  },
}

return object
