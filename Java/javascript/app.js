'use strict';

var Cube       = require('./Cube'),
    CubeSolver = require('./CubeSolver');

function main() {
    var cubeFaces = [];

    var cube = new Cube(cubeFaces);

    CubeSolver.solve(cube);

    console.log('My Cube:', cube.toString());
}

main();
