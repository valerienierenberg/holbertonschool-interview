#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list):
    """recursive function that queries the Reddit API and returns
    a count of all hot articles for a given subreddit"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'My User Agent 1.0'}
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code != 200:
        return 0
    data = response.json()
    count = 0
    for post in data['data']['children']:
        title = post['data']['title']
        for word in word_list:
            if word in title:
                count += 1
    if data['data']['after'] is not None:
        count += count_words(subreddit, word_list)
    return count