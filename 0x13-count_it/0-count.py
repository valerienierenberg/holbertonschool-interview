#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list):
    """function that queries the Reddit API and returns
    a count of all hot articles for a given subreddit"""
    url = 'https://www.reddit.com/r/{}/hot.json?limit=100'.format(subreddit)
    headers = {'User-Agent': 'custom'}
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code == 404:
        return 0
    else:
        response = response.json()
    for post in response['data']['children']:
        for word in word_list:
            if word in post['data']['title']:
                return 1 + count_words(subreddit, word_list)
