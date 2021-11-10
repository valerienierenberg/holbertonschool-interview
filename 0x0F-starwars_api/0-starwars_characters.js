#!/usr/bin/node

const request = require('request');
const process = require('process');

request.get('https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/', function (err, response, body) {
  if (err) {
    console.log(err);
  } else {
    const whole = JSON.parse(body);
    for (const char of whole.characters) {
      request.get(char, function (err, res, body) {
        if (err) {
          console.log(err);
        }
        const wholeChars = JSON.parse(body);
        orderedChars[character] = wholeChars;
        if (Object.values(orderedChars).length === characters.length) {
          characters.forEach(character => {
            console.log(orderedChars[character]);
          });
        }
      });
    }
  }
});
