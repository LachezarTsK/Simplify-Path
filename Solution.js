
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function (path) {
    const DIRECTORY_SEPARATOR = "/";
    const CURRENT_DIRECTORY = ".";
    const DIRECTORY_UP_A_LEVEL = "..";

    const elements = path.split(DIRECTORY_SEPARATOR);
    const stackElements = [];
    for (const element of elements) {
        if (element === CURRENT_DIRECTORY || element.length === 0) {
            continue;
        }
        if (element === DIRECTORY_UP_A_LEVEL && stackElements.length !== 0) {
            stackElements.pop();
        } else if (element !== DIRECTORY_UP_A_LEVEL) {
            stackElements.push(element);
        }
    }
    return DIRECTORY_SEPARATOR + stackElements.join(DIRECTORY_SEPARATOR);
};
