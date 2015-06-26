'use strict';

/**
 * CubeHelper
 *
 * Contains methods to perform operations on a Cube object
 */
function CubeHelper() {

}

// NOTE:  I don't use prototype here.  That's because these
// are public static methods, so no need to do 'new CubeHelper()'


CubeHelper.turnFaceCW = function (cube) {
    // Do operations needed on cube
};

CubeHelper.turnFaceCCW = function (cube) {

};

CubeHelper.performOperations = function (cube, operations) {
    var self = this;
    
    // Perform each operation
    operations.forEach(function (operation) {
        self[operation](cube);
    });
}

module.exports = CubeHelper;
