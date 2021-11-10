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
        const wholeChars = JSON.parse(body);
        if (err) {
          console.log(err);
        } else {
          console.log(wholeChars.name);
        }
      });
    }
  }
});
