'use strict';

var CubeHelper = require('./CubeHelper');

/**
 * CubeSolver
 *
 * Solves cube
 */
function CubeSolver() {
}

CubeSolver.solve = function (cube) {
    // NOTE:  Somehow you'll probably want this method
    // to also return a list of operations.  You can then
    // pass that list of operations to your CubeViewController
    // that will pass it off to whatever is rendering your cube
    // animations

    this._orient(cube);
};

CubeSolver._orient = function (cube) {

    // You can call one operation
    CubeHelper.turnFaceCW(cube);

    // Or you can pass a whole array of operations
    CubeHelper.performOperations(cube, [
        'turnFaceCW',
        'turnFaceCCW'
    ]);
};

module.exports = CubeSolver;

// NOTE:  You could also write it like this since you are only using static methods
/*
var CubeSolver = {

    solve: function (cube) {

    },

    _orient = function (cube) {

    }
};*/
