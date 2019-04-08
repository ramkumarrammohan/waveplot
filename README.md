# waveplot
Simple proto to draw sawtooth waveform


Waveform - Custom qml component
1. Inherited from QQuickItem
1. Used to show waveform on screen.
2. Uses QSGGeomtryNode & QSGGeomtry to plot the waveform

SawtoothGenerator - Data provider
1. `getPlot` ill give the point to draw one vertical line on particular pixel.
2. Struct `Point` is having the information about the pixel coordinates(x position, y1&y2 position).

Logic:
1. Instantiated the geometry with the `QSGGeometry::defaultAttributes_Point2D()` & `2000` vertices
2. In a for loop fill the 2000 vertices with data provided by `getPlot` call.

Note: Here one vertical line of length=5pix has been drawn on every pixels with same 5pix Increment between 1-x pixel.
So the line seems to be having the jagging effect.
Is there a way to make this smooth sawtooth wave without jagging effect?
