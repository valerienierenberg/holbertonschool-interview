#!/usr/bin/node

const request = require('request');
const args = process.argv;
const filmUrl = 'https://swapi.co/api/films/' + args[2];

request(filmUrl, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    let json = JSON.parse(body);
    let characters = json.characters;
    let count = 0;
    for (let i = 0; i < characters.length; i++) {
      request(characters[i], function (error, response, body) {
        if (error) {
          console.log(error);
        } else {
          let json = JSON.parse(body);
          console.log(json.name);
          count++;
          if (count === characters.length) {
            process.exit(0);
          }
        }
      });
    }
  }
});
