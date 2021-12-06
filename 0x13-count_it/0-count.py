#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list, after=None):
    """recursive function that queries the Reddit API and returns
    a count of all hot articles for a given subreddit"""
    url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(subreddit,
                                                                after)
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) '
                             'AppleWebKit/537.36 (KHTML, like Gecko) '
                             'Chrome/76.0.3809.100 Safari/537.36'}
    r = requests.get(url, headers=headers, allow_redirects=False)
    if r.status_code != 200:
        return 0
    data = r.json()
    posts = data.get('data').get('children')
    count = 0
    for post in posts:
        if word_list is None:
            return count
        post_data = post.get('data')
        title = post_data.get('title')
        for word in word_list:
            if word in title:
                count += 1
    after = data.get('data').get('after')
    if after is None:
        return count
    return count + count_words(subreddit, word_list, after)
