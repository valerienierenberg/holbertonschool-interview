#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a list containing the titles of all hot articles for a given
subreddit. If no results are found for the given subreddit, the
function should return None."""
import json
import requests
from sys import argv


def count_words(subreddit, word_list):
    """recursive function that queries the Reddit API and returns
    a list containing the titles of all hot articles for a given
    subreddit. If no results are found for the given subreddit, the
    function should return None."""
    url = 'https://www.reddit.com/r/{}/hot.json?limit=100'.format(subreddit)
    headers = {'User-Agent': 'My User Agent 1.0'}
    response = requests.get(url, headers=headers)
    if response.status_code != 200:
        return None
    data = response.json()
    for post in data['data']['children']:
        for word in word_list:
            if word in post['data']['title']:
                print(post['data']['title'])
    if data['data']['after'] is not None:
        count_words(subreddit, word_list)
