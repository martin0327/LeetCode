/**
 * @param {string} s
 * @return {string}
 */
// var clearStars = function(s) {
    
    
    
// };

var clearStars = function(s) {
    const n = s.length;
    const idx = Array.from({ length: 26 }, () => []);
    const check = Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        if (s[i] === '*') {
            check[i] = 1;
            for (let j = 0; j < 26; j++) {
                if (idx[j].length) {
                    check[idx[j].pop()] = 1;
                    break;
                }
            }
        } else {
            idx[s.charCodeAt(i) - 'a'.charCodeAt(0)].push(i); // a -> 0 , b -> 1 ... z -> 25
        }
    }

    let ans = '';
    for (let i = 0; i < n; i++) {
        if (!check[i]) {
            ans += s[i];
        }
    }

    return ans;
};

