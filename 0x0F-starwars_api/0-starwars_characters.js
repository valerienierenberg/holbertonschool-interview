#!/usr/bin/node

const request = require('request');
const args = process.argv;
const filmUrl = `https://swapi-api.hbtn.io/api/films/${args[2]}`;

request(filmUrl, function (error, response, body) {
  if (error) {
    console.log(error);
  }
  const characters = JSON.parse(body).characters;
  const orderedCharacters = {};
  characters.forEach(function (character) {
    request(character, function (error, response, body) {
      if (error) {
        console.log(error);
      }
      const characterName = JSON.parse(body).name;
      orderedCharacters[characterName] = character;

      if (Object.keys(orderedCharacters).length === characters.length) {
        console.log(orderedCharacters);
      }
    });
  });
});
