'use strict';

/**
 * Cube
 *
 * This is your cube model.  Only use this for cube data.
 *
 * This will help you when you want to start hooking up
 * views to your cube for the front end
 *
 * @param {array} data Cube data
 */
function Cube(data) {
    // Public var
    this.exampleCubeData = [];

    if (data) {
        this.setData(data);
    }
}

Cube.prototype.setData = function (data) {
    // Do any preprocessing on data

    // Set the data
    this.exampleCubeData = data;


};

// Use to string instead of print
Cube.prototype.toString = function () {
    return this.exampleCubeData.join(',');
};

module.exports = Cube;
