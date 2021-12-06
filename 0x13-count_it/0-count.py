#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list):
    """recursive function that queries the Reddit API and returns
    a count of all hot articles for a given subreddit"""
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    header = {'User-Agent': 'My User Agent 1.0'}
    params = {'limit': 100}
    response = requests.get(url, headers=header, params=params)
    if response.status_code == 404:
        return 0
    response_json = response.json()
    children = response_json.get('data').get('children')
    titles = [child.get('data').get('title') for child in children]
    for word in word_list:
        count = titles.count(word)
        print("{}: {}".format(word, count))
    after = response_json.get('data').get('after')
    if after:
        return count_words(subreddit, word_list)
